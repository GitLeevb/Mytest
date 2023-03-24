第一次推送项目至github遇到的问题：
Connection closed by remote host---解决办法：ping一下github.com是否出错，在cmd中运行ping github.com查看。
                                   发现出错——找一个可以连接的ip，以xxx.xx.xxx.xxx github.com 的格式放进hosts文件,
                                    host目录C:\Windows\System32\drivers\etc
could not read from remote repository——解决办法：在.ssh文件夹下新建config文件然后保存以下命令：
                                                     # github
                                                     Host github.com
                                                     HostName github.com
                                                     PreferredAuthentications publickey
                                                     IdentityFile ~/.ssh/id_rsa
                                                     Port 22
其他关于tortoise的配置主要有：
首先git bash生成ssh密钥对，在github新建远程仓库并在settings添加公钥；
然后在tortoise将ssh客户端修改为git的ssh.exe；
配置相应的远端，添加私钥等操作。
要将项目上传远程仓库，首先需要在本地创建版本库，将项目添加到工作目录也就是.git所在目录；
此时项目所在的是暂存区，还需要提交到当前分支。