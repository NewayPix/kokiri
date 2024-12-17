# Kokiri - Tests

This folder contains simple projects that tests the capabilities of Kokiri
itself. To compile the tests you'll need to navigate within each test folder
and change a parameters if you are using `premake gmake2`.

This is because I haven't fixed the premake file to correctly include the
project files and libraries folder. Whenever you open a generated Makefile
you will see something like this:

`-I../kokiri/src`

The problem is that kokiri doesn't level just *one* level up. You'll have to
change it to the following:

`-I../../kokiri/src`

And the same goes for library folders.
