from django.db import models
from django.urls import reverse
from django.contrib.auth.models import AbstractUser


class RealUser(AbstractUser):
    public_key = models.TextField(null=True)
    e = models.TextField(null=True)
    def __str__(self):
        return self.username


class CustomUser(models.Model):
    public_key = models.TextField(null=True)
    e = models.TextField(null=True)
    username = models.TextField()

    def get_absolute_url(self):
        return reverse('users', kwargs={'pk': self.pk})

    def __str__(self):
        return self.username

class Message(models.Model):
    cyphertext = models.TextField(null=True)
    sender = models.ForeignKey(CustomUser, related_name="sender", on_delete=models.CASCADE)
    receiver = models.ForeignKey(CustomUser, related_name="receiver", on_delete=models.CASCADE)

    def get_absolute_url(self):
        return reverse('message-detail', kwargs={'pk': self.pk})

    def __str__(self):
        return self.cyphertext
