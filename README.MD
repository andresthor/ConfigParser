# ConfigParser
A simple class that imitates some of the basic features of the python configParser.

## Motivation
The need for a minimalistic class to parse config files that have the form

```
[Category]
parameter = value
otherParam = value

[OtherCategory]
thisIsAlsoValid:value
asIsThis :value
andThis= value

```

## Aim
To expand on the basic capabilities until it behaves similarly to python's configParser

## Requirements
c++11 and cmake3.1

## License
MIT

