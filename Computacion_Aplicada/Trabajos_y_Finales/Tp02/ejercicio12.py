#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# In[2]:


df= pd.read_csv('C:/Users/andre/OneDrive/Escritorio/InfAplicadaTP02/Ejercicio12/datoejercicio12.csv')


# In[3]:


df


# In[4]:


print(df.columns)


# In[5]:


print(df.dtypes)


# In[6]:


print(df.info)


# In[7]:


df


# In[ ]:





# In[22]:


velocidadMaxima=df.agg('Basilea Wind Speed [10 m]').max()


# In[23]:


velocidadMaxima


# In[25]:


velocidadMinima=df.agg('Basilea Wind Speed [10 m]').min()


# In[26]:


velocidadMinima


# In[ ]:





# In[27]:


temperaturaMaxima=df.agg('Basilea Temperature [2 m elevation corrected]').max()


# In[28]:


temperaturaMaxima


# In[29]:


temperaturaMinima=df.agg('Basilea Temperature [2 m elevation corrected]').min()


# In[30]:


temperaturaMinima


# In[ ]:





# In[36]:


print(df.head(n=50))


# In[ ]:




