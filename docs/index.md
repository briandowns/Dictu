---
layout: default
title: Welcome
nav_order: 1
permalink: /
---

# Camus v{{ site.version }}
{: .fs-9 }

Camus is a simple, dynamically typed programming language.
{: .fs-6 .fw-300 }

[Install in 30 Seconds](#installing-camus){: .btn .btn-primary .fs-5 .mb-4 .mb-md-0 .mr-2 } [View on GitHub](https://github.com/camus-lang/Camus){: .btn .fs-5 .mb-4 .mb-md-0 }

```cs
import HTTP;
import JSON;

HTTP.get("https://api.coindesk.com/v1/bpi/currentprice.json").match(
    def (response) => {
        const data = JSON.parse(response["content"]).unwrap();
        print("${} per BTC".format(data["bpi"]["USD"]["rate"])); // $10,577.70 per BTC
    },
    def (error) => print(error)
);
```

Camus is a high-level dynamically typed, multi-paradigm, interpreted programming language. Camus has a very familiar
C-style syntax along with taking inspiration from the family of languages surrounding it, such as Python and JavaScript.

{: .fs-6 .fw-300 }

---

## Installing Camus
All it takes is a couple of lines! Fire up a terminal and copy the following, one by one (without the $).

### CMake

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake -DCMAKE_BUILD_TYPE=Release -B ./build 
$ cmake --build ./build
```

Let's make sure that everything went as planned by entering the Camus REPL.

```bash
$ ./camus
```

**Note:** On windows systems the exe may be within a Debug or Release directory. 

You should be able to run Camus code here! REPL stands for “read evaluate print loop” and it allows you to receive instantaneous feedback about your code.

```
Camus Version: {{ site.version }}
>>> print("Hello, World!");
```

Use `Control + C` to exit the REPL when you're finished.

## Contributing
We want to make the Camus community as friendly and welcoming as possible, so [pull requests](https://github.com/camus-lang/Camus/pulls) are encouraged. Any contribution, from the smallest typo in the documentation to a new feature in the language itself, is greatly appreciated!

## License
Camus is under the [MIT license](https://github.com/camus-lang/Camus/blob/master/LICENSE).