# -*- coding: utf-8 -*-
"""
Created on Tue Apr 30 20:08:29 2019

@author: YYHAO
"""


from keras.models import Sequential  

from keras.layers import Input, Dense, Dropout, Activation

from keras.models import Model

from keras import optimizers

from keras.optimizers import SGD

from keras.datasets import imdb

import numpy as np

import matplotlib.pyplot as plt

 

tBatchSize = 512

Epochs = 20

 

model = Sequential() 

model.add(Dense(500,input_shape=(10000,))) 

model.add(Activation('relu'))

model.add(Dropout(0.5)) 

 

model.add(Dense(500))

model.add(Activation('relu'))

model.add(Dropout(0.5))

 

model.add(Dense(100)) 

model.add(Activation('relu'))

model.add(Dropout(0.3))

 

model.add(Dense(16)) 

model.add(Activation('relu'))

model.add(Dropout(0.1))

 

model.add(Dense(1)) 

model.add(Activation('sigmoid'))

model.summary()

 

model.compile(loss='binary_crossentropy', optimizer=optimizers.RMSprop(lr = 0.001),metrics=['acc'])

 

def vectorize_sequences(sequences,dimention = 10000):

    results = np.zeros((len(sequences),dimention))

    for i,sequence in enumerate(sequences):

        results[i,sequence] = 1.

    return results

 

 #load data

(X_train, y_train), (X_test, y_test) = imdb.load_data(num_words = 10000)

 

 

 

X_train = vectorize_sequences(X_train)

X_test = vectorize_sequences(X_test)

 

y_train = np.asarray(y_train).astype('float32')

y_test = np.asarray(y_test).astype('float32')

 

history = model.fit(X_train, y_train, batch_size=tBatchSize, epochs=Epochs, verbose=2,shuffle=True, validation_split=0.3)

 

score = model.evaluate(X_test,y_test, batch_size=tBatchSize)

print("The score:",score[0])

print("Tne accuracy:",score[1])

 

history_dic = history.history

loss_values = history_dic['loss']

val_loss_values = history_dic['val_loss']

acc = history_dic['acc']

val_acc = history_dic['val_acc']

 

epochs = range(1,len(loss_values)+1)

fig = plt.figure()

 

ax1 = fig.add_subplot(111)

ax1.plot(epochs,loss_values,'bo',label = 'Training loss')

ax1.plot(epochs,val_loss_values,'b',label = 'Validation loss')

plt.title("Training and validstion loss")

plt.xlabel("Epochs")

plt.ylabel("Loss")

plt.legend(bbox_to_anchor=(1,0),loc = 3,borderaxespad = 0)

plt.show()

'''

ax2 = fig.add_subplot(111)

ax2.plot(epochs,acc,'bo',label = 'Training acc')

ax2.plot(epochs,val_acc,'b',label = 'Validation acc')

plt.title("Training and validstion accuracy")

plt.xlabel("Epochs")

plt.ylabel("Accuracy")

plt.legend(bbox_to_anchor=(1,0),loc = 3,borderaxespad = 0)



plt.show()

'''
