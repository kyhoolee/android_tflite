#!/bin/bash

curl -sc /tmp/cookie "https://drive.google.com/uc?export=download&id=1WpsN4D9N2JXAlbbimxK9KbzY_Fzf00tN" > /dev/null
CODE="$(awk '/_warning_/ {print $NF}' /tmp/cookie)"
curl -Lb /tmp/cookie "https://drive.google.com/uc?export=download&confirm=${CODE}&id=1WpsN4D9N2JXAlbbimxK9KbzY_Fzf00tN" -o resources.tar.gz
tar -zxvf resources.tar.gz
rm resources.tar.gz

echo Download finished.
