# Constraints

Using C file manipulation functions is forbidden

# Reference

If something should always exist and never change, use a references

A reference !=  new variable

A reference doesn't occupy memory

A reference = an aliase for an existing variable

A reference = a constant pointer, always points to the same variable, we can't change it 

Reference = a dereferenced pointer

A reference can't point to nothing

```
   std::string &sREF = s;
// std::string             тип, на который объявляется ссылка
//             &sREF       переменная типа ссылка на string
//                     s   переменная, на которую объявляется ссылка
```
# Pointer

If something should not always exist and can change, use a pointer

A pointer can be pointing to a non-existing address

# ex03

HumanA has one weapon forever => the classe HumanA has `Weapon& weaponREF` attribut
HumanB cabn change weapon     => the classe HumanB has `Weapon* weaponPTR` attribut
On the both cases we can change the type of the weapon 
