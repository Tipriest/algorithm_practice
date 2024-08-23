import requests
import parsel
from prettytable import PrettyTable
import os
"""搜索下载"""
# 找搜索接口
#   - 歌名
#   - 歌曲ID 
# 分析不同歌曲，数据包有什么变化
headers = {
    'User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36'
}
key = input('请输入你要搜索的歌曲/歌手:')
#   请求网址
search_url = f'https://www.gequbao.com/s/{key}'
#   发送请求
search_response = requests.get(url =search_url, headers=headers)
# 2.获取响应json数据
html = search_response.text
# print(html)
import parsel
# 把html字符串数据转换为可解析对象
selector = parsel.Selector(html)
tb = PrettyTable()
tb.field_names = ['序号', '歌手', '歌名']
# 定义序号变量
page = 0
info = []
# 定位类名为row的所有标签，第一个和最后一个不要，做一个切片
rows = selector.css('.row')[1:-1]
# for循环遍历，提取其中元素
for row in rows:
    title = row.css('.text-primary::text').get().strip()
    music_id = row.css('.text-primary::attr(href)').get().split('/')[-1]
    singer = row.css('.text-success::text').get().strip()
    # 添加字段内容
    tb.add_row([page, singer, title])
    page += 1
    dict = {
        '歌名':title,
        'id':music_id,
        '歌手':singer
    }
    info.append(dict)
print(tb)
# 输入下载的歌曲序号：
num = input('输入下载的歌曲序号：')
download_id = info[int(num)]['id']
download_title = info[int(num)]['歌名']
download_singer = info[int(num)]['歌手']

url = f'https://www.gequbao.com/api/play_url?id={download_id}&json=1'
#   发送请求
response = requests.get(url =url, headers=headers)
# 2.获取响应json数据
json_data = response.json()
#   print(json_data)
#   解析数据,提取歌曲链接
play_url = json_data['data']['url']
music_content = requests.get(url=play_url, headers=headers).content
with open(os.path.join(os.getcwd(), f'{download_title}-{download_singer}.mp3'), mode = 'wb') as f:
    f.write(music_content)

