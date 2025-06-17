from typing import List
from queue import Queue

class Solution:
    def generateTag(self, caption: str) -> str:
        contents:list = caption.split(' ')
        result:list = []
        result.append('#')
        space_left:int = 99
        
        for index, content in enumerate(contents):
            if space_left == 99:
                result.append(content.lower())
            else:
                result.append(content.capitalize())
            space_left -= len(content)
            if space_left<0:
                break
        value:list =  list(''.join(result))
        return ''.join(value[0:100])
            
        
        
if __name__ == "__main__":
    solution = Solution()
    caption = " fPysaRtLQLiMKVvRhMkkDLNedQKffPnCjbITBTOVhoVjiKbfSawvpisDaNzXJctQkn"
    result = solution.generateTag(caption)
    print(f"result = {result}")
 