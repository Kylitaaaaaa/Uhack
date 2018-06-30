from django.http import JsonResponse
from django.shortcuts import render
from .models import stoplight
from django.http import HttpResponse
from django.core import serializers
import serial
import sqlite3
import json
from django.core.serializers.json import DjangoJSONEncoder
from rest_framework.views import APIView
from rest_framework.response import Response
from django.contrib.auth import get_user_model

User = get_user_model()
# Create your views here.
class DatabaseManager():
    def __init__(self):
        self.conn = sqlite3.connect("C:/Users/sherwin calalan/Documents/GitHub/Uhack/adaptivetraffic/db.sqlite3")
        self.conn.execute('pragma foreign_keys = on')
        self.conn.commit()
        self.cur = self.conn.cursor()

    def add_del_update_db_record(self, sql_query, args=()):
        self.cur.execute(sql_query, args)
        self.conn.commit()
        return

    def __del__(self):
        self.cur.close()
        self.conn.close()


def graph(request):
    dataRaw = stoplight.objects.values('trafficLoad')
    data = json.dumps(list(dataRaw), cls=DjangoJSONEncoder)
    data = ''.join(
        c for c in str(data) if c not in ':<abcdefghijklnopqrtuvwxyz/\\\'ABCDEFGHIJKLMNOPQRSTUVWXYZ"m[]{} ')

    return JsonResponse(data, safe=False)

def graphChart(request):
    dataRaw = stoplight.objects.all()

    return render(request, 'graph.html')

class Chart(APIView):
    authentication_classes = []
    permission_classes = []

    def get(self, request, format=None):
        load = stoplight.objects.values_list('trafficLoad', flat=True)

        data = {
            "trafficLoad": load,

        }

        return Response(data)



