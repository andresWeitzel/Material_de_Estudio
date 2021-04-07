#!/usr/bin/env python
# coding: utf-8

# In[4]:


def isPrime(num):
    if num < 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2, num):
            if num % i == 0:
                return False
        return True            

def app():
    num = int(input('Ingresar un numero: '))
    result = isPrime(num)

    if result is True:
        print('Es numero primo!!')
    else:
        print('No es numero primo!!')

if __name__ == '__main__':
    app()


# In[ ]:




