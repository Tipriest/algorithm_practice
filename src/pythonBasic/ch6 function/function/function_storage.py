def find_factor(nums):
    """
    Args:
        nums (non-negative integer): _description_
    """
    if((type(nums) != 0) | nums < 0):
        raise ValueError('Input should be a non-negative integer')
    i = 1
    str1 = ""
    while i <= nums:
        if(nums % i == 0):
            str1 = str1 + " " + str(i)
        i += 1
    return str1