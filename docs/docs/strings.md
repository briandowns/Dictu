---
layout: default
title: Strings
nav_order: 4
---

# Strings
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

## Strings

Strings in Camus are an immutable data type. This means that once a string has been created, there is no way to modify a string directly. Instead, a new string is created. Strings are indicated with quotation marks. In Camus, you can use `'single'` or `"double"` quotes. They are treated the same.

### Concatenation

Use a plus sign to join string together. This is called concatenation.

```cs
"This item costs " + "27" + " euros"; // "This item costs 27 euros"
```

### Indexing

You can access a specific letter in a string with the same syntax you would use to access an item in a list.

```cs
var string = "Camus";

string[0]; // D
string[-1]; // u
string[100]; // String index out of bounds.

for (var i = 0; i < x.len(); i += 1) {
    print(string[i]);
}
// D
// i
// c
// t
// u
```

### Slicing

Slicing is technique used when we wish to return a substring. It has a syntax of <string>[start:end] where start and end are optional
as long as one is provided.

If you want to get only part of a string, you slice it! To slice a string, use square brackets with the range you want to slice. The starting index is inclusive, but the ending index is exclusive. You can also use negative numbers to get characters from the end of a string.

```cs
"Camus"[1:]; // ictu
"Camus"[:4]; // Dict
"Camus"[1:4]; // ict
"Camus"[2:4]; // ct
"Camus"[100:101]; // '' (empty string)
"Camus"[0:100]; // Camus
```

### Escape codes

“Escape codes” are used to create things like new lines and tabs. Because backslashes are used in escape codes, you need to type two backshashes (`\\`) to use a single backslash.

| \n | \n is the escape code for a new line |
| \r | \r is the escape code for a carriage return |
| \t | \t is the escape code for a horizontal tab |
| \v | \v is the escape code for a vertical tab |
| \x\<hh> | \x is the escape code for a hex value of hh |
| \\\ | \\\ is the escape code for a backslash |
| \\" | \\" is the escape code for double quotes |
| \\' | \\' is the escape code for single quotes |

You should only need the escape codes for single and double quotes if you are using that type of quote within a string indicated with the same type. If that doesn't make sense, you'll quickly realize it won't work when you come across it.

#### Raw strings

Sometimes, you wil need to ignore escape codes. Simply prefix your string with an `r` and any escape codes will be ignored.

```cs
// Normal Strings
"Camus\trocks!"; // 'Camus  rocks!'
// Raw Strins
r"Camus\trocks!"; // 'Camus\trocks!'
r"Camus\trocks!".len(); // 12
```

### string.len() -> Number

Returns the length of the given string.

```cs
"string".len(); // 6
```

### string.lower() -> String

Returns a lowercase version of the given string.

```cs
"CAMUS".lower(); // camus
"DiCtU".lower(); // camus
"camus".lower(); // camus
```

### string.upper() -> String

Returns an uppercase version of the given string.

```cs
"camus".upper(); // CAMUS
"DiCtU".upper(); // CAMUS
"CAMUS".upper(); // CAMUS
```

### string.toNumber() -> Number

Casts a string to a number. This method returns a Result type and will unwrap to a number.

```cs
"10.2".toNumber().unwrap(); // 10.2
"10".toNumber().unwrap(); // 10
"10px".toNumber(); // <Result Err>
```

### string.toBool() -> Boolean

Casts a string to a boolean value. Any string except an empty string is considered `true`.

```cs
"".toBool(); // false
"false".toBool(); // true
```

### string.startsWith(string) -> Boolean

Returns true if a string starts with a given string.

```cs
"Camus".startsWith("D"); // true
"Camus".startsWith("Dict"); // true
"Camus".startsWith("Camus"); // true
"Camus".startsWith("q"); // false
"Camus".startsWith("d"); // false
```

### string.endsWith(string) -> Boolean

Returns true if a string ends with a given string.

```cs
"Camus".endsWith("u"); // true
"Camus".endsWith("tu"); // true
"Camus".endsWith("Camus"); // true
"Camus".endsWith("ut"); // false
"Camus".endsWith("q"); // false
"Camus".endsWith("U"); // false
```

### string.split(String: delimiter, Number: splitCount -> Optional) -> List

Returns a list of strings, split based on a given delimiter.
Returns a list of all characters in a string if an empty string is passed as delimiter.

An optional second argument can be passed which will determine the amount of times a split occurs, if negative it's the same
as not passing a value and will split by all occurrences of the delimiter.
```cs
"Camus is awesome!".split(" "); // ['Camus', 'is', 'awesome!']
"Camus is awesome!".split(" ", -1); // ['Camus', 'is', 'awesome!']
"Camus is awesome!".split(""); // ["D", "i", "c", "t", "u", " ", "i", "s", " ", "a", "w", "e", "s", "o", "m", "e", "!"]
"Camus is awesome!".split(" ", 0); // ['Camus is awesome!']
"Camus is awesome!".split(" ", 1); // ['Camus', 'is awesome!']
```

### string.replace(String: old, String: new) -> String

Replaces part (a substring) of a string with another string.

```cs
"Camus is okay...".replace("okay...", "awesome!"); // "Camus is awesome!"
```

### string.contains(String) -> Boolean

Returns true if a string contains another string.

```cs
"Camus is awesome!".contains("Camus"); // true
"Camus is awesome!".contains("Camus is awesome!"); // true
```

### string.find(String, Number: skip -> Optional) -> Number

To find the index of a given substring, use the `.find()` method. This method takes an optional second parameter which can be used to skip the first `n` number of appearances of the substring. This method returns `-1` if the substring could not be found. Otherwise, it returns the index of the string.

```cs
"Hello, how are you?".find("how"); // 7
"hello something hello".find("hello", 2); // 16 (Skipped first occurrence)
"House".find("Lost Keys"); // -1 (Not found)
```

### string.leftStrip() -> String

Strips whitespace from the left side of a string and returns the result.

```cs
"     Camus".leftStrip(); // "Camus"
```

### string.rightStrip() -> String

Strips whitespace from the right side of a string and returns the result.

```cs
"Camus     ".rightStrip(); // "Camus"
```

### string.strip() -> String

Strips whitespace from both sides of a string and returns the result.

```cs
"     Camus     ".strip(); // "Camus"
```

### string.format(...value: args...) -> String

This method will replace any instances of `{}` with the provided parameters. It also casts all arguments to strings.

```cs
"Hello {}".format("Jerome"); // "Hello Jerome"
"Hello".format("Jerome"); // Error: format() placeholders do not match arguments
"Hello {}".format(); // Error: format() placeholders do not match arguments
"String: {}, Number: {}, Boolean: {}, List: {}, Dictionary: {}".format("String", 123, true, ["String", 123, true], {"key": "value"}); // "String: String, Number: 123, Boolean: true, List: ["String", 123, true], Dictionary: {"key": "value"}"
```

### string.count(String) -> Number

Returns the number of occurrences of a given substring within another string.

```cs
"Camus is great!".count("Camus"); // 1
"This documentation".count("Good jokes"); // 0
"Sooooooooooome characters".count("o"); // 11
```

### string.title() -> String

Returns a title cased version of string with first letter of each word capitalized.

```cs
"camus language".title(); // Camus Language
"this documentation".title(); // This Documentation
"once upon a time".title(); // Once Upon A Time
```

### string.repeat(Number) -> String

Returns a new string with the original string repeated the given number of times.

```cs
"ba"+"na".repeat(2); // banana
"la".repeat(2) + " land"; // lala land
```