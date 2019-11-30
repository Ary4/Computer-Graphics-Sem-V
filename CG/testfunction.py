import math

class test:
  def name(self):
    return "Test"
  def lo(self):
    return [0 for _ in range(2)]
  def up(self):
    return [math.sqrt(5) for _ in range(2)]
  def dim(self):
    return 2
  def fitness(self,sol):
    return [sol[0]**2 + sol[1]**2-5]