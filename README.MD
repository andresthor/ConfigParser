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

## Status
- [x] Initial commit
- [x] First version of readme
- [x] Add license
- [ ] Define required features
- [ ] Set clear milestones
- [ ] Define exact requirements for milestones
- [ ] Add unittests


## Requirements
c++11 and cmake3.1

## License
MIT

