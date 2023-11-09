---
layout: default
title: IO
nav_order: 9
parent: Standard Library
---

# IO
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

## IO

To make use of the IO module an import is required.

```cs
import IO;
```

### IO.print(...values) -> Nil

Prints a given list of values to stdout.

```cs
IO.print(0);
// 0
```

### IO.println(...values) -> Nil

Prints a given list of values to stdout with an appended newline character.

```cs
IO.println("Camus!");
// Camus!
```

### IO.copyFile(String: src, String: dst) -> Result\<Nil>

Copies the contents from the source file to the destination file.

Returns a Result type and on success will unwrap to nil.

```cs
IO.copyFile(src, dst);
```
