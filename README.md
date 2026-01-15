## Password generator for linux in C
Simple and no 3rd party deps - only libc and linux capabils.
## Build
```
gcc src/main.c -o genpas
```
Or with `-O2` if needed.  
## Run it
`genpas` - generates password with random length of 10-20 alphanumeric 
characters.   
`genpas 9` - generates 9 alphanumeric chars length password.   
`genpas -s 10` or `genpas 10 -s` - generates 10 chars length password 
(alphanumeric + special chars).   
