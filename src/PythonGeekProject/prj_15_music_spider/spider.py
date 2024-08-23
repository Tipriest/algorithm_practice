import requests
import parsel
import prettytable
import os
# 1.单首歌曲采集 2.搜索下载功能 3.把py程序打包成单个exe文件
"""Python爬虫实现基本流程"""
# 1.数据来源分析 (a)明确需求 (b)抓包分析 
# 2.代码实现步骤 (a)发送请求 (b)获取数据 (c)解析数据 (d)保存数据
"""单首歌曲采集"""
# 网址：https://www.gequbao.com/music/61636
# 抓包分析，通过浏览器对应的开发者工具分析对应的数据位置
# (a)打开开发者工具 (b)刷新网页 (c)通过关键字搜索找到对应位置
#   (c)关键字逻辑：需要什么数据就搜索什么数据
#       1.先找歌曲链接地址(播放地址)：开发者工具->网络->媒体->查看对应歌曲链接
# 1.发送请求
#   模拟浏览器
headers = {
    'User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36'
}
#   请求网址
url = 'https://www.gequbao.com/api/play_url?id=61636&json=1'
#   发送请求
response = requests.get(url =url, headers=headers)
# 2.获取响应json数据
json_data = response.json()
#   print(json_data)
#   解析数据,提取歌曲链接
play_url = json_data['data']['url']
print(play_url)
# 3.保存数据
music_content = requests.get(url = play_url, headers= headers).content
with open(os.path.join(os.getcwd(), 'a.mp3'), mode='wb') as f:
    f.write(music_content)