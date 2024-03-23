#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

struct player
{
    bool equipped;
    int hp = 4, siz = 4, right, left, id, behave = 0;
    char card[N];
} a[11];

int n, m, en, top;
char pile[N];
bool ed;
void choupai(int p, int num)
{ // 抽牌
    while (num--)
    {
        a[p].card[++a[p].siz] = pile[top];
        if (top > 1)
            --top;
    }
}

void dying(int fr, int to)
{ // 濒死阶段
    int i;
    for (i = 1; i <= a[to].siz; i++)
    {
        if (a[to].card[i] == 'P')
        {
            a[to].card[i] = '0';
            ++a[to].hp;
            return; // 这个阶段只能把血量回到1
        }
    }
    a[a[to].right].left = a[to].left;
    a[a[to].left].right = a[to].right;
    if (a[to].id == 3)
        --en;
    if (!en || a[to].id == 1)
    {
        ed = 1;
        return;
    } // 摸牌晚于判断结束
    if (a[to].id == 3)
        choupai(fr, 3);
    if (a[to].id == 2 && a[fr].id == 1)
    {
        a[fr].siz = 0, a[fr].equipped = 0;
    }
}

void atk(int fr, int to)
{ // 杀
    int i;
    for (i = 1; i <= a[to].siz; i++)
    {
        if (a[to].card[i] == 'D')
        {
            a[to].card[i] = '0';
            return;
        }
    }
    --a[to].hp;
    if (!a[to].hp)
        dying(fr, to);
}

bool parry(int fr, int to, int flag)
{
    int i = fr, j;
    do
    {
        if (flag)
        {
            if (a[to].behave == a[i].id || (a[to].behave == 1 && a[i].id == 2) || (a[to].behave == 2 && a[i].id == 1))
            {
                // 第一次无懈可击：助攻
                for (j = 1; j <= a[i].siz; j++)
                {
                    if (a[i].card[j] == 'J')
                    {
                        a[i].card[j] = '0';
                        a[i].behave = a[i].id;
                        return !parry(i, fr, 0);
                    }
                }
            }
        }
        else
        {
            if (((a[i].id == 1 || a[i].id == 2) && a[fr].behave == 3) || (a[i].id == 3 && (a[fr].behave == 1 || a[fr].behave == 2)))
            {
                // 无懈可击套娃：打断上一次
                for (j = 1; j <= a[i].siz; j++)
                {
                    if (a[i].card[j] == 'J')
                    {
                        a[i].card[j] = '0';
                        a[i].behave = a[i].id;
                        return !parry(i, fr, 0);
                    }
                }
            }
        }
        i = a[i].right;
    } while (i != fr);
    return 0;
}

void duel(int fr, int to)
{
    int i, l, r;
    if (parry(fr, to, 1))
        return;
    if (a[fr].id == 1 && a[to].id == 2)
    { // 这个特判要看目标的实际身份
        --a[to].hp;
        if (a[to].hp <= 0)
            dying(fr, to);
        return;
    }
    l = 1, r = 1;
    while (1)
    {
        while (r <= a[to].siz && a[to].card[r] != 'K')
            ++r;
        if (r > a[to].siz)
        {
            --a[to].hp;
            if (a[to].hp <= 0)
                dying(fr, to);
            return;
        }
        else
            a[to].card[r] = '0';
        // 目标先弃牌
        while (l <= a[fr].siz && a[fr].card[l] != 'K')
            ++l;
        if (l > a[fr].siz)
        {
            --a[fr].hp;
            if (a[fr].hp <= 0)
                dying(to, fr);
            return;
        }
        else
            a[fr].card[l] = '0';
    }
}

void invade(int fr)
{
    int i = a[fr].right, j;
    for (; i != fr; i = a[i].right)
    {
        if (parry(fr, i, 1))
            continue;
        for (j = 1; j <= a[i].siz; j++)
        {
            if (a[i].card[j] == 'K')
            {
                a[i].card[j] = '0';
                break;
            }
        }
        if (j > a[i].siz)
        { // 省一个变量的判断方式
            --a[i].hp;
            if (a[i].id == 1 && !a[fr].behave)
                a[fr].behave = 4;
            if (!a[i].hp)
                dying(fr, i);
            if (ed)
                return;
        }
    }
}

void shoot(int fr)
{
    int i = a[fr].right, j;
    for (; i != fr; i = a[i].right)
    {
        if (parry(fr, i, 1))
            continue;
        for (j = 1; j <= a[i].siz; j++)
        {
            if (a[i].card[j] == 'D')
            {
                a[i].card[j] = '0';
                break;
            }
        }
        if (j > a[i].siz)
        {
            --a[i].hp;
            if (a[i].id == 1 && !a[fr].behave)
                a[fr].behave = 4;
            if (a[i].hp <= 0)
                dying(fr, i);
            if (ed)
                return;
        }
    }
}

void check()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("%d %d hp=%d\n", a[i].id, a[i].behave, a[i].hp);
        for (j = 1; j <= a[i].siz; j++)
        {
            printf("%c ", a[i].card[j]);
        }
        puts("");
    }
    puts("");
}

void solve()
{
    if (!en)
        return;
    int i = 0, j, k;
    char now;
    bool used;
    while (!ed)
    {
        used = 0;
        choupai(i, 2);
        for (j = 1; j <= a[i].siz; j++)
        {
            if (a[i].card[j] == '0' || a[i].card[j] == 'D')
                continue;
            if (!a[i].hp)
                break;
            // tao diaoxiejiuchi
            if (a[i].card[j] == 'P')
            {
                if (a[i].hp < 4)
                {
                    ++a[i].hp;
                    a[i].card[j] = '0';
                }
                continue;
            }
            // sha
            if (a[i].card[j] == 'K')
            {
                if (used && !a[i].equipped)
                    continue;
                k = a[i].right; // k为这个人的右手边
                // 主公对类反贼 忠诚对类反贼 反贼对忠诚和主公
                if ((a[i].id == 1 && a[k].behave != 3 && a[k].behave != 4) || (a[i].id == 2 && a[k].behave != 3) || (a[i].id == 3 && a[k].behave != 1 && a[k].behave != 2))
                    continue;
                a[i].card[j] = '0';
                atk(i, k);
                // 这个人的表现就变成了他的身份（忠不跳反，反不跳忠）
                a[i].behave = a[i].id;
                used = 1;
                if (ed)
                    return;
                continue;
            }
            // juedou
            if (a[i].card[j] == 'F')
            {
                if (a[i].id == 3)
                {
                    a[i].card[j] = '0';
                    duel(i, 0);
                    a[i].behave = a[i].id;
                    if (ed)
                        return;
                    j = 0;
                }
                else
                {
                    k = a[i].right;
                    while (k != i)
                    {
                        if ((a[i].id == 1 && a[k].behave >= 3) || (a[i].id == 2 && a[k].behave == 3))
                        {
                            a[i].card[j] = '0';
                            duel(i, k);
                            a[i].behave = a[i].id;
                            if (ed)
                                return;
                            j = 0;
                            break;
                        }
                        k = a[k].right;
                    }
                }
                continue;
            }
            // aoe
            // aoe可能会让忠反互跳
            // nanman
            if (a[i].card[j] == 'N')
            {
                a[i].card[j] = '0';
                invade(i);
                if (ed)
                    return;
                j = 0;
                continue;
            }
            // wanjian
            if (a[i].card[j] == 'W')
            {
                a[i].card[j] = '0';
                shoot(i);
                if (ed)
                    return;
                j = 0;
                continue;
            }
            // wuqi-zhugeliannu
            if (a[i].card[j] == 'Z')
            {
                a[i].card[j] = '0';
                a[i].equipped = 1;
                j = 0;
                continue;
            }
        }
        i = a[i].right;
    }
}
int main()
{
    int i, j;
    char s[3];
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        if (s[0] == 'M')
            a[i].id = a[i].behave = 1;
        if (s[0] == 'Z')
            a[i].id = 2;
        if (s[0] == 'F')
            a[i].id = 3, ++en;
        a[i].equipped = 0;
        a[i].left = (i - 1 + n) % n, a[i].right = (i + 1) % n;
        for (j = 1; j <= 4; j++)
        {
            scanf("%s", s);
            a[i].card[j] = s[0];
        }
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%s", s);
        pile[i] = s[0];
    }
    reverse(pile + 1, pile + m + 1);
    top = m;
    solve();
    if (a[0].hp <= 0)
        puts("FP");
    else
        puts("MP");
    for (i = 0; i < n; i++)
    {
        if (a[i].hp <= 0)
            puts("DEAD");
        else
        {
            for (j = 1; j <= a[i].siz; j++)
            {
                if (a[i].card[j] != '0')
                    putchar(a[i].card[j]), putchar(' ');
            }
            puts("");
        }
    }
    return 0;
}
