from django.conf.urls import url
from . import views

urlpatterns = [

    url(r'^graph/$', views.graph, name='graph'),
    url(r'^chart/$', views.Chart.as_view()),
    url(r'^graphChart/$', views.graphChart, name='graphChart'),

]