# Python 实现TSP问题

标签（空格分隔）： 未分类

---

- 递归的方法实现 
重要的是理解递归的思想 
在实现所有城市的排序时，可以分别先拿出一个城市来，然后找出剩下的城市所有可能的排序，而剩下的城市排序如何找出，可以在剩下的这些城市中再分别拿出一个城市来，然后再剩下的城市所有可能的排序。。如此循环直到初始条件一个城市的情况，有点类似于n!的情况 
递归的时候先由后往前，直到找到初始条件，此时是入栈的过程，而后由初始条件往后计算，此时是出栈的过程，最后完全计算出结果

- 遍历选择路径
```python
#城市列表
city = [1,2,3,4,5]
#城市间的距离
dist = (
        (0,1,3,4,5),
        (1,0,1,2,3),
        (3,1,0,1,2),
        (4,2,1,0,1),
        (5,3,2,1,0)
        )
#城市排序 路径
path = []
#路径成本计算
def distcal(path,dist):
    sum_dist = 0
    for i in range(0,len(path)-1):
        di = dist[int(path[i])-1][int(path[i+1])-1]
        sum_dist = sum_dist + di
    #最后回去的一条路径
        di = dist[int(path[len(path)-1])-1][path[0]-1]
        sum_dist = sum_dist + di
    return sum_dist
#路径递归
def perm(l):
    if len(l)<=1:
        return [l]
    r = []
    for i in range(len(l)):
        #构造不包含这个城市的列表
        s = l[:i] + l[i+1:]
        p = perm(s)
        for x in p:
            r.append(l[i:i+1]+x)
    return r
```
随机选择路径
```python
#随机选择路径
def randompath(path):
    #复制一份path，防止破坏原path
    copypath = path[:]
    #随机选择的path
    rdpath = []
    loop = True
    while loop:
        if len(copypath) <=1:
            path.append(random.choice(copypath))
            loop = False
        else:
            temp = random.choice(copypath)
            path.append(temp)
            copypath.remove(temp)
    return path
```
贪心法选择路径
```python
#贪心法选择路径
#参数传入城市列表和城市间的距离
def greedy(city,dist):
    #选择一个城市做为开始城市
    startcity = 2
    #排好序的城市列表 存放已经找好的城市
    sortedcitys = []
    #将第一个城市加入排序列表
    sortedcitys.append(startcity)
    #开始循环
    for i in range(0:len(city)):
```



