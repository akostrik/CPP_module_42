# Reference

If something should always exist and never change, use a references

Reference !=  new variable

Reference doesn't occupy memory

A reference = an aliase for existing variables

A reference = a constant pointer, we can't change where the reference is pointing to, it always points to the same variable

Reference = a dereferenced pointer

A reference can't point to nothing

```
   std::string &stringREF = s;
// std::string                  тип, на который объявляется ссылка;
//             &stringREF       переменная типа ссылка на string
//                          s   переменная, на которую объявляется ссылка
```
# Pointer

If something should not always exist and can change, use a pointer

A pointer can be pointing to a non-existing address
