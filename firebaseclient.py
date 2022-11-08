import os
from datetime import datetime
import time
import random
os.environ["GOOGLE_APPLICATION_CREDENTIALS"]="firebase.json"

import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

# Log In
cred = credentials.Certificate('firebase.json')
app = firebase_admin.initialize_app()
db = firestore.client()

sensor_1_ref = db.collection(u'Sensor_1')
docs = sensor_1_ref.stream()

#for doc in docs:
#    print(f'{doc.id} => {doc.to_dict()}')

while(True):
    current_date = datetime.now()
    date = current_date.strftime('%Y-%m-%d')
    hour = current_date.strftime('%H')
    print(date)
    print(hour)
    collection_name = u'sensor_1_{0}'.format(date)
    hour_ref = db.collection(collection_name).document(hour)
    encendido = bool(random.getrandbits(1))
    hour_docs = hour_ref.get()
    hour_data = hour_docs.to_dict()
    if hour_data == None:
        hour_ref.set({
            u'minutos_encendido' : 1 if encendido else 0,
            u'minutos_apagado' : 1 if not encendido else 0 ,
        })
    else:
        if encendido:
            hour_ref.update({
                u'minutos_encendido': hour_data[u'minutos_encendido'] +1
            })
        else:
            hour_ref.update({
                u'minutos_apagado': hour_data[u'minutos_apagado'] +1
            })            
    time.sleep(60)