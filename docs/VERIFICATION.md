# 实验复测记录

复测日期：2026-10-07（Asia/Shanghai）。使用隔离副本，未修改本地原仓库或实验实现。环境：Ubuntu、RISC-V GCC 13.3.0、QEMU 8.2.2。以下是本地评分脚本结果，不是课程提交成绩。

为避免 QEMU 调试端口冲突，各测试使用独立 GDBPORT。首次发生端口冲突的结果未采纳。部分实验的扣分来自缺失 `time.txt` 或问答文件，需与功能失败分别看待。

## util

原始分支提交：`e5d86de0d97a8e2fe9c707855c7c2f54f68a9e91`。命令：`make grade GDBPORT=26101`；退出码：`2`。

```text
sleep, no arguments: OK (1.6s)
sleep, returns: OK (1.2s)
sleep, makes syscall: OK (1.0s)
pingpong: OK (1.0s)
primes: OK (1.0s)
find, in current directory: OK (1.1s)
find, recursive: OK (1.1s)
xargs: OK (1.0s)
time: FAIL
Score: 99/100
```

[完整评分输出](verification/util.log)。
