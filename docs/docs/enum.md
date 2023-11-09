---
layout: default
title: Enums
nav_order: 11
---

# Enums
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

## Enums

Enums are a collection of constants which can be accessed via a name rather than
an index to document intent. Unlike other languages, enums in Camus do not generate a value
based on the previous entry, instead if no value is assigned it will be given it's position
within the enum, 0-based, as a value.

```cs
enum MyEnum {
    a, // 0
    b, // 1
    c  // 2
}

print(MyEnum.a); // 0

enum Test {
    a = 10, // 10
    b,      // 1
    c       // 2
}

print(Test.a); // 10
```

Enums in Camus also do not care about the value being stored within the enum, so
if you wanted to create a heterogeneous enum, Camus will not stop you.

```cs
enum HeterogeneousEnum {
    a = 0,
    b = "string",
    c = def () => 10
}
```

### Enum.values()

To get all values within an Enum you can use the `.values()` method. This will return a dictionary.

```cs
enum Test {
    a = 10, // 10
    b,      // 1
    c       // 2
}

print(Test.values()); // {"c": 2, "a": 10, "b": 1}
```