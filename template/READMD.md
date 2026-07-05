# ICPC Template Library

This directory contains my ICPC template source files, compiled using Xelatex, and printed as a PDF for use as reference material during ICPC competitions.

You can clone only this directory as follows:

```
git clone --depth 1 --no-checkout https://github.com/nopostpone/sync2024.git
cd sync2024

git sparse-checkout init --cone

git sparse-checkout set template

git checkout main
```

To compile, run **twice** the following command in this directory (requires TeX Live 2024, XeLaTeX):

```
latexmk -xelatex main.tex
```

Run the command above twice, because the first run will not generate a directory.

Due to differences in Xelatex versions, this template **does not contain Chinese characters**. To add Chinese characters, please add the necessary package files according to your environment.

The file structure is well-organized. You can replace the directory with your own code and formula snippets by modifying the references in `main.tex`.