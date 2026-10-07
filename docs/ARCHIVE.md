# 完整历史备份

[Release](https://github.com/Sylvialline/xv6-labs-2021/releases/tag/archive-2026-10-07) 中的 [`xv6-labs-2021-original-2026-10-07.tar.gz`](https://github.com/Sylvialline/xv6-labs-2021/releases/download/archive-2026-10-07/xv6-labs-2021-original-2026-10-07.tar.gz) 保留原始 Git 历史和本地未提交内容。

原始远程来源：`git://g.csail.mit.edu/xv6-labs-2021`。

SHA-256：`a283d877ae4a91e5bb9facdc07271344a6f8020cc5ac8aed7718335130bec2eb`。已核对 GitHub 返回的附件摘要。

附件包含：

- `original.bundle`：所有原始分支、远程分支、标签及 stash 可达的 Git 对象；额外保存 reflog 残留提交。
- `inventory.json`：留档时的 HEAD、分支、远程来源、状态和原始 ref / SHA 对照。
- `staged.patch`、`unstaged.patch`：已暂存和未暂存的修改。
- `untracked.tar.gz`：未跟踪文件。

被 `.gitignore` 忽略且未纳入 Git 的编译产物未上传；已提交的生成文件完整保留在 bundle 中。

## 恢复

在新目录中解压附件后，可以完整恢复原始 refs：

```bash
git clone --mirror original.bundle restored.git
git clone restored.git restored
cd restored
git switch my-util
```

如需恢复当时未提交的内容，在 `restored` 目录按顺序应用非空补丁，并解压未跟踪文件（附件解压于上一级目录）：

```bash
if test -s ../staged.patch; then git apply --index ../staged.patch; fi
if test -s ../unstaged.patch; then git apply ../unstaged.patch; fi
tar -xzf ../untracked.tar.gz
```

原始 stash 位于镜像的 `refs/stash`；`archive/stash-0` 分支用于浏览同一提交。stash 的第二个父提交为 index 快照；存在第三个父提交时，其保存未跟踪文件。可以从 bundle 恢复这些原始对象。

## 原始引用与公开分支

| 原始引用 | 原始 SHA | 公开分支 / 标签 |
| --- | --- | --- |
| `refs/heads/my-syscall` | `1e6e6cafbb26a898b8c3f90e819fc5e7227dc8af` | `my-syscall` |
| `refs/heads/my-util` | `91bd19f7ec5bcbc0fa84d4b0c109df1414944c5f` | `my-util` |
| `refs/heads/syscall` | `1e6e6cafbb26a898b8c3f90e819fc5e7227dc8af` | `syscall` |
| `refs/heads/util` | `e5d86de0d97a8e2fe9c707855c7c2f54f68a9e91` | `util` |
| `refs/remotes/origin/cow` | `c9818915934504523e52a33e2755b7aff54c495e` | `upstream/cow` |
| `refs/remotes/origin/fs` | `46bcbaf1f2b638ede67e3dd1fcccee226a772fa5` | `upstream/fs` |
| `refs/remotes/origin/lock` | `281b66cf19660eb15c4542b63693c74a9ced0467` | `upstream/lock` |
| `refs/remotes/origin/mmap` | `2255a4ca32a31faeacd902855b77080e3ccbdd8f` | `upstream/mmap` |
| `refs/remotes/origin/net` | `1bd9c80b1ef5eb70b91bbd1dbea9c1d953cdc555` | `upstream/net` |
| `refs/remotes/origin/pgtbl` | `1e6b2dec7d5ca49571e426ccc6cd686d009b6d07` | `upstream/pgtbl` |
| `refs/remotes/origin/riscv` | `a1da53a5a12e21b44a2c79d962a437fa2107627c` | `upstream/riscv` |
| `refs/remotes/origin/syscall` | `1e6e6cafbb26a898b8c3f90e819fc5e7227dc8af` | `upstream/syscall` |
| `refs/remotes/origin/thread` | `7e0a45c6e73c5552d913ae49d090b9a11bbd95f9` | `upstream/thread` |
| `refs/remotes/origin/traps` | `219a8d7d70b6ac66b1447aeada079a1f8c3027f7` | `upstream/traps` |
| `refs/remotes/origin/util` | `f654383cdec479c9d53a02bffa1ab5526f6c3ca4` | `upstream/util` |

仅在 reflog 中残留的原始提交：`35dd52efd1343dd0fb7340b77a28728f9ca8364f`, `73ed59397a6312167416066964687409257720bc`, `cf2f003037a04427c21492112ed477e3e3ea8e68`。
