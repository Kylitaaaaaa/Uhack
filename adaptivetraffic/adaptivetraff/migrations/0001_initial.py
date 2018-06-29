# Generated by Django 2.0.4 on 2018-06-29 16:49

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='sensor',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('sensorID', models.CharField(max_length=20)),
                ('stoplightID', models.CharField(max_length=20)),
                ('sensorType', models.CharField(max_length=100)),
            ],
        ),
        migrations.CreateModel(
            name='stoplight',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('stoplightID', models.CharField(max_length=20)),
                ('location', models.CharField(max_length=1000)),
                ('trafficLoad', models.IntegerField()),
                ('colorPhase', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='violation',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('violationID', models.CharField(max_length=20)),
                ('violationType', models.CharField(max_length=1000)),
                ('plateNumber', models.CharField(max_length=20)),
                ('sensorID', models.CharField(max_length=20)),
            ],
        ),
    ]
