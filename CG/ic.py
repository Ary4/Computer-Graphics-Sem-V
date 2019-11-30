import math
import random
import time
import functools,operator
#from sorting import *
from testfunction import *

def fitness(sol):
	return sol[0]**2 + sol[1]**2-5

def crossover(a,b):
	x=[]
	for i in range(len(a)):
		ra=random.random()
		if(ra<0.3):
			x.append(a[i])
		elif(ra<0.6):
			x.append(b[i])
		else:
			m=random.random()
			x.append(m*a[i]+(1-m)*b[i])
	return mutation(x)

def mutation(solution):
    p=random.random()
    an=[]
    for i in range(len(solution)):
    	mutation_prob = random.random()
    	if(mutation_prob<0.06):
    		p=random.random()
    		if(p<0.5 and solution[i]+0.03*(max_x-min_x)<=max_x):
    			an.append(solution[i]+random.uniform(0,0.03)*(max_x-min_x))
    		elif(p>0.5 and solution[i]-0.03*(max_x-min_x)>=min_x):
    			an.append(solution[i]-random.uniform(0,0.03)*(max_x-min_x))
    		else:
    			an.append(solution[i])
    	else:
    		an.append(solution[i])
    return an





n = 100
max_gen = 50
min_x=0
max_x=math.sqrt(5)
d=2
nof=[]
chromosome=[[random.uniform(0.0,max_x) for j in range(d)] for i in range(0,n)]

print(chromosome)

gen_no=0
ti=[]
nof=[]
f=[]
for i in range(n): 
  f.append([i+1])
  f[i].append(fitness(chromosome[i]))
f.sort(key = lambda x: x[1])
print(f)
while(gen_no<max_gen):
	print(5+f[0][1])
	for i in range(n): 
	  f[i].append(fitness(chromosome[i]))
	f.sort(key = lambda x: x[1])
	chromosome2=[]
	f2=[]
	for i in range(int(0.3*n)):
		chromosome2.append(chromosome[f[i][0]-1])
	while(len(chromosome2)!=2*n):
		a1 = random.randint(0,len(chromosome2)-1)
		b1 = random.randint(0,len(chromosome2)-1)
		chromosome2.append(crossover(chromosome2[a1],chromosome2[b1]))

	for i in range(n): 
  		f2.append([i+1])
  		f2[i].append(fitness(chromosome2[i]))
	f2.sort(key = lambda x: x[1])
	f=f2
	gen_no=gen_no+1

print(5+f[0][1])

















