# Ray Install

Ubuntu 22.04

## 安装minicoda
```bash
# 下载安装脚本
$ wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
# 添加执行权限
$ chmod u+x Miniconda3-latest-Linux-x86_64.sh
# 运行安装脚本
$ ./Miniconda3-latest-Linux-x86_64.sh
```

根据提示选择安装目录,自动

重启终端后,提示符之前出现`(base)`

## 创建env4ray

```bash
# 创建一个名为env4ray，版本为x.x.x(你需要的python版本)的python环境
$ conda create --name ray python=x.x.x
```

遇到报错:
```
Collecting package metadata (current_repodata.json): failed

ProxyError: Conda cannot proceed due to an error in your proxy configuration.
Check for typos and other configuration errors in any '.netrc' file in your home directory,
any environment variables ending in '_PROXY', and any other system-wide proxy
configuration settings.

```

解决方法:
```
$ unset all_proxy && unset ALL_PROXY
```
再次运行创建环境指令

创建完成后,显示如下:
```bash                                                                  
# To activate this environment, use                                             
#                                                                               
#     $ conda activate env4ray
#
# To deactivate an active environment, use
#
#     $ conda deactivate

```

根据提示输入
```bash
$ conda activate env4ray
```

提示符前`(base)`变成`(env4ray)`则证明进入env4ray环境,需要退出时则使用如下命令:

```bash
$ conda deactivate
```

## 安装ray

为加速下载指定了阿里的镜像源
```bash
$ pip install -i https://mirrors.aliyun.com/pypi/simple --trusted-host mirrors.aliyun.com -U 'ray[default]'
```