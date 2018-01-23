# Python实现蒙特卡罗算法计算圆周率

标签（空格分隔）： 未分类

---

蒙特卡洛算法：随机模拟方法
```python
import random
import math
#用蒙特卡罗算法计算圆周率
total = 0
print("请输入点数：")
n = int(input())
for i in range(n):
    x,y = random.random(),random.random()
    if math.sqrt(x**2+y**2)<1:
        total += 1
pi = total/n*4
print("pi:",pi)

```

```python
import random
import math
#用蒙特卡罗算法计算圆周率
n = 10**4
print(sum(1 if random.random()**2 + random.random()**2 <1 else 0 for i in range(n))*4/n)

```




