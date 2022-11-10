#!/bin/sh

#Modo de usar:
curl -s <em>http://github.c/script.sh</em> | bash
stty -echo
read -p "Insira a senha: " pass
stty echo
echo "\n#################<VSCODE>#################"
echo $pass | sudo -S snap install --classic code
echo "\n#################<GCC E G++>#################"
echo $pass | sudo -S apt-get install g++ gcc
echo "\n#################<GIT>#################"
echo $pass | sudo -S apt-get install git-all
echo "\n#################<VSCODE>#################"
code --install-extension ms-vscode.cpptools