from django import forms
from django.contrib.auth.forms import UserCreationForm, UserChangeForm
from .models import RealUser

class RealUserCreationForm(UserCreationForm):

    class Meta:
        model = RealUser
        fields = ('username', 'email', 'public_key', 'e')

class RealUserChangeForm(UserChangeForm):

    class Meta:
        model = RealUser
        fields = ('username', 'email')