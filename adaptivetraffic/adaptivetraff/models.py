from django.db import models

# Create your models here.
class stoplight(models.Model):
    stoplightID = models.CharField(max_length=20)
    location = models.CharField(max_length=1000)
    #status = models.CharField(max_length=20)
    #statusChangeTime = models.DateTimeField()
    trafficLoad = models.IntegerField()
    colorPhase = models.CharField(max_length=50)

class violation(models.Model):
    violationID = models.CharField(max_length=20)
    violationType = models.CharField(max_length=1000)
    plateNumber = models.CharField(max_length=20)
    sensorID = models.CharField(max_length=20)

class sensor(models.Model):
    sensorID = models.CharField(max_length=20)
    stoplightID = models.CharField(max_length=20)
    sensorType = models.CharField(max_length=100)