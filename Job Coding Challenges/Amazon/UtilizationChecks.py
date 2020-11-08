import math
def finalInstances(instances, averageUtil):
    """
    :type instances: int
    :type averageUtil: List[int]
    :rtype: int
    """ 
    wait = 0
    for util in averageUtil:
        if wait == 0:
            if util < 25:
                wait = 0 if(instances == 1) else 10
                instances = math.ceil(instances /2 )
            elif util > 60:
                wait = 0 if(instances == 2* 10^8) else 10
                instances = min(2* 10**8, instances *2)
        else:
            wait = wait -1
    return instances