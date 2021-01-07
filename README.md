# stn

![Windows](https://github.com/Nullsson/stn/workflows/Windows/badge.svg?branch=master)
![Linux](https://github.com/Nullsson/stn/workflows/Linux/badge.svg?branch=master)
![MacOs](https://github.com/Nullsson/stn/workflows/MacOs/badge.svg?branch=master)

stn is a collection of in-house libraries used in C/C++ projects at Nullsson.
Inspired by Sean Barrett's talk [Advice for Writing Small Programs in C](https://www.youtube.com/watch?v=eAhWIO1Ra6M), his popular [stb](https://github.com/nothings/stb) libraries and the [Handmade Movement](https://handmade.network/manifesto). We decided to use this as our startingpoint when moving towards software we can all be proud of.

## Usage

stn is structured in a way where the user only have to include `stn.h`. Which modules to include is specified using different defines above your include. Example:

```C
#define STN_USE_MATH
#define STN_USE_STRING
#include "stn.h"
```

There is also `STN_USE_ALL` for you who want to include all the modules.

For a more complete documentation with what all the different modules include we recommend you looking over our test code located in this repository's test folder. More in-depth documentation will be provided at a later date.

If you have any feature requests please submit an issue in the  [issues page](https://github.com/Nullsson/stn/issues) and we will look into it.

## Contributing

Thank you for considering contributing to stn. We are always looking to improve the library in any way possible wether its documentation, improvements or bugfixes. If you are interested in contributing please find an issue in the [issues page](https://github.com/Nullsson/stn/issues) and "claim" the issue. If there is no issue for the bug / improvement you are looking to make then please create one before you submit your pull request.

### Developing

Library development involves mostly developing together with your tests. We have created a project called [HyperTest](https://github.com/Nullsson/HyperTest) to aid us in our work. In order to write tests for your code when contributing to stn you can follow our documentation for HyperTest.

HyperTest is procided as a git submodule to this repository hence when cloning this project with intention of development you have to run:

```cmd
git submodule init
git submodule update
```

for HyperTest to actually be cloned as well.

## License

MIT License

Copyright (c) 2021 Nullsson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
