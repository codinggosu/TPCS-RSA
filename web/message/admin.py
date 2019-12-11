from django.contrib import admin
from django.contrib.auth import get_user_model
from django.contrib.auth.admin import UserAdmin
from .forms import RealUserCreationForm, RealUserChangeForm
from .models import RealUser
from .models import *

admin.site.register(CustomUser)
admin.site.register(Message)


class RealUserAdmin(UserAdmin):
    add_form = RealUserCreationForm
    form = RealUserChangeForm
    model = RealUser
    list_display = ['email', 'username',]

admin.site.register(RealUser, RealUserAdmin)