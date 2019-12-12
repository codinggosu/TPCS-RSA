from django.urls import path
from django.contrib import admin
from django.urls import path, include
from django.views.generic.base import TemplateView
from message.views import *

urlpatterns = [
    # path('', views.MessageListView, name='index'),
    path('users/', include('django.contrib.auth.urls')),
    path('users/signup/',SignUpView.as_view(), name='signup'),
    path('', RealUserListView.as_view(), name='home'),
    path('users/<int:pk>', CustomUserDetailView.as_view(), name='article-detail'),
    path('createuser/', CustomUserCreateView.as_view(), name='user-create'),
    

]
