from django.urls import path

from message.views import *

urlpatterns = [
    # path('', views.MessageListView, name='index'),
    path('users/', CustomUserListView.as_view(), name='user-list'),
    path('user-detail/<int:pk>', CustomUserDetailView.as_view(), name='article-detail'),
    path('createuser/', CustomUserCreateView.as_view(), name='user-create'),
    

]
