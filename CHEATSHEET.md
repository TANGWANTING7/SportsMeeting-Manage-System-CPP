# 第一部分 关于git

- 每次开始写代码之前，在这个文件夹的终端(Ctrl+`)执行"git pull origin main" (将github仓库上的代码拉回本地)

- 写完代码之后，执行以下命令：

```
git add .
git commit -m "本次提交的注释"
git push -u origin main
```

- 指令执行完后无误即可

# 第二部分 关于Cmake

- 第一次编译之前，应当在项目根目录执行以下命令

```
mkdir build
cmake .
```

指令执行完后即可进行下一步

- 每次编译时在项目根目录执行以下命令

```
cd build
cmake --build .
```

- 若执行无误后，二进制文件会生成在bin目录下，在bin目录执行以下命令即可运行程序

```
./SportsMeetingSystem.exe
```