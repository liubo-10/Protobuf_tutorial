# git笔记

## 添加密钥gitlab

ssh-keygen -t rsa -C liubo@zerozero.cn

ssh-add    /home/liubo/00-liubo/my_project/git_config/gitlab_rsa

ssh -T  git@git.zerozero.cn

## 添加密钥gihub

ssh-keygen -t rsa -C liubojinzhou@sina.cn

ssh-add    /home/liubo/00-liubo/my_project/git_config/github_rsa

ssh -T git@github.com

## git设置文件

Host gitlab

HostName git.zerozero.cn

User liubo00

IdentityFile /home/liubo/00-liubo/my_project/git_config/id_rsa

Host github.com

HostName github.com

User liubo

IdentityFile /home/liubo/00-liubo/my_project/git_config/github_rsa

添加配置文件

git config --file /home/liubo/00-liubo/my_project/git_config/.gitconfig
