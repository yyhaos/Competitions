# -*- coding: utf-8 -*-
"""
Created on Tue Apr 30 20:15:53 2019

@author: YYHAO
"""
name=r'origin_data.xlsx'
#name=r'part_data.xlsx'

import xlrd
import xlwt
import codecs,sys
def delstopword(line,stopkey):#删停用词
    wordList = line.split(' ')          
    sentence = ''
    for word in wordList:
        word = word.strip()
        if word not in stopkey:
            if word != '\t':
                sentence += word + " "
    return sentence.strip()
    
class Comment(object):#评论结构体
    class comment(object):
        def __init__(self,keyword,tieziID,content,fenci,contentID,time,userID):
            self.keyword=keyword
            self.tieziID=tieziID
            self.content=content
            self.contentID=contentID
            self.fenci=fenci
            self.time=time
            self.userID=userID
    
    def mkComment(self,keyword,tieziID,content,fenci,contentID,time,userID):
        return self.comment(keyword,tieziID,content,fenci,contentID,time,userID)
    
def readtext(filename):
    return open(filename).read().splitlines()


def readexcel(filename, sheetNO=0):
    book = xlrd.open_workbook(filename)
    sh=book.sheet_by_index(sheetNO)
    cols=sh.ncols
    rows=sh.nrows
    print('open file:' ,'cols=',cols,'rows=',rows)
    return sh
   # for r in range(rows):
   #     value = sh.cell_value(rowx=r,colx=0)


print(name)
stopkey = [w.strip() for w in codecs.open('stopWord.txt', 'r', encoding='utf-8').readlines()]
origin_sh= readexcel(name)
cols=origin_sh.ncols
rows=origin_sh.nrows
line={}
comment=Comment();
cnt=0
for i in range(rows):#读取评论信息到结构体
    if(i==0):
        continue
    keyword=origin_sh.cell(i,0).value.encode('GBK')
    tieziID=origin_sh.cell(i,1).value
    try:
        content=str(origin_sh.cell(i,2).value)
    except:
        print(origin_sh.cell(i,2).value,'跳过了此条评论')
        continue
    try:
        fenci=str(origin_sh.cell(i,3).value)
    except:
        print(origin_sh.cell(i,3).value,'跳过了此条评论')
        continue
    #fenci=origin_sh.cell(i,3).value.encode('GBK')
    contentID=origin_sh.cell(i,4).value
    time=origin_sh.cell(i,5).value.encode('GBK')
    userID=origin_sh.cell(i,6).value
    line[cnt]=comment.mkComment(keyword,tieziID,content,fenci,contentID,time,userID)
    cnt+=1
print('共有',cnt,'条评论成功建结构')
labels={}#记录分类的数据量

for i in range(cnt):#对评论分词的去停用词（预处理）
    #print(str(line[i].keyword,'GBK'))   
    if(str(line[i].keyword,'GBK') not in labels):
        labels[str(line[i].keyword,'GBK')]=0
    labels[str(line[i].keyword,'GBK')]=labels[str(line[i].keyword,'GBK')]+1
#    line[i].fenci.drop_invalid(initial_words=initial_words,max_rate=0.6)
    #print(line[i].fenci)
    line[i].fenci=delstopword(line[i].fenci,stopkey)
    #print(line[i].fenci.split(' '))
    
#无效词组
wuxiao=readtext('wuxiao.txt')
#有效词组
youxiao=readtext('youxiao.txt')
print(  youxiao)
you_cnt=0
you_line={}
for i in range(cnt):#对评论有用与否
    fenci_array = line[i].fenci.split(' ')
    wucnt=0
    youcnt=0
    for j in fenci_array:
        #if(j=='素颜'):
           # print(j)
           # print(j in youxiao)
            
        if(j in wuxiao):
            wucnt=wucnt+1
        if(j in youxiao):
            youcnt=youcnt+1
    if((youcnt-2*wucnt)>1):
        you_line[you_cnt]=line[i]
        you_cnt=you_cnt+1

print('有效数：',you_cnt) 
for i in range(you_cnt):#对评论有用与否
    print(you_line[i].fenci)
savebook = xlwt.Workbook(encoding = 'GBK')
savesheet = savebook.add_sheet('youxiao sheet')
for i in range(you_cnt):    
    savesheet.write(i,0, label = str(you_line[i].keyword,'GBK'))
    savesheet.write(i,1, label = you_line[i].tieziID)
    savesheet.write(i,2, label = you_line[i].content)
    savesheet.write(i,3, label = you_line[i].contentID)
    savesheet.write(i,4, label = you_line[i].fenci)
    savesheet.write(i,5, label = str(you_line[i].time))
    savesheet.write(i,6, label = str(you_line[i].userID))
    
    
savebook.save('youxiao workbook p1.xls')

#for i in labels.keys():
#    print (str(  i),':',labels[i])


#lie={}
#for i in range(rows):
#    lie[origin_sh.cell(i,0).value.encode('GBK')] = origin_sh.cell(i,2).value
#    print(origin_sh.cell(i,0).value.encode('GBK'),lie[origin_sh.cell(i,0).value.encode('GBK')])
#print(guanjianci)