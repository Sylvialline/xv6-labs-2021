# xv6-labs-2021

我的 MIT 6.S081 2021 年实验代码。主要在 2025 年 2 月完成 Unix utilities；2026 年 4 月又补充了一种 primes 实现。

## 分支与进度

| 分支 | 内容与状态 |
| --- | --- |
| `util` | 2025-02-25–26：sleep、pingpong、primes、find、xargs 均已实现；功能测试全部通过 |
| `my-util` | 包含以上实现，另有 2026-04-27 的 `primes_new.c`；新实现未单独验证 |
| `syscall / my-syscall` | 与官方初始代码一致，未在本年份实现 |

[对应年份课程网站](https://pdos.csail.mit.edu/6.S081/2021/)。

## 复测摘要（2026-10-07）

| 分支 | 评分 | 说明 |
| --- | --- | --- |
| `util` | 99/100 | 功能全部通过，缺少 time.txt |

## 查看代码

默认分支 `codex/archive` 放置留档说明和当时的工作区快照。切换到实验分支查看各实验实现：

```bash
git clone https://github.com/Sylvialline/xv6-labs-2021.git
cd xv6-labs-2021
git switch my-util
```

实验依赖 RISC-V 工具链、QEMU、make 和 Python 3。实验分支通常使用 `make qemu` 运行、`make grade` 评分；切换不同实验后先执行 `make clean`。参考仓库和 xv6 基础仓库不保证包含每个实验的评分脚本。

## 留档说明

2026-10-07 整理自本地 `~/xv6/xv6-labs-2021`。原始提交的作者和日期保留；`upstream/*` 是当时本地保存的上游分支快照，`archive/reflog-*` 保存仅在 reflog 中残留的版本。原有 `README` 和许可证保留。

[完整备份和恢复说明](docs/ARCHIVE.md) · [2026-10-07 复测记录](docs/VERIFICATION.md)。本次留档未修复实验实现。
