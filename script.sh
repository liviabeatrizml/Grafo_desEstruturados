#!/bin/sh
stty -echo
read -p "Insira a senha: " pass
stty echo
printf '\n'
echo "\n#################<VSCODE>#################"
echo $pass | sudo -S snap install --classic code
echo "\n#################<GCC E G++>#################"
echo $pass | sudo -S apt-get install g++ gcc
echo "\n#################<GIT>#################"
echo $pass | sudo -S apt-get install git-all
echo "\n#################<EXTENSIONS>#################"
code --install-extension ms-vscode.cpptools