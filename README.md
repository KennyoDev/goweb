# GOWEB




### Fast, simple way to enter the web while in Terminal 





##### This project is using cJSON to read the JSON file for the website domains.

https://github.com/DaveGamble/cJSON




```

Copyright (c) 2009-2017 Dave Gamble and cJSON contributors




Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions

```





## Installing

To install, you will need:

- gcc

- Python




Clone the Git repo and enter your config in the Python script.

Also, this is for Linux; that's why I set the PATH to local/bin.

***To use it you will need to update the paths in the jsonHandlerFuncs.h(line: 13 and 78) and in the python script(line: 7)***




## Basic usage

```

goweb youtube

```

This will open YouTube on Firefox.

More sites will be added by me, but you can also just do it yourself.

### With '-n' you can add a new Website:
```
goweb -n example example.com
```

### To specify the browser you can use 
```
-f for firefox
-c for chromium
-z for zen-browser
```
Example:
```
goweb -c github
```

