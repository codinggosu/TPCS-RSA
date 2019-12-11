from django.views.generic.edit import CreateView
from django.views.generic.list import ListView
from django.views.generic.detail import DetailView
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse_lazy
from .models import CustomUser


class CustomUserListView(ListView):
    model = CustomUser

    # def get_context_data(self, **kwargs):
    #     context = super().get_context_data(**kwargs)
    #     return context

class CustomUserDetailView(DetailView):
    model = CustomUser

    # def get_context_data(self, **kwargs):
    #     context = super().get_context_data(**kwargs)
    #     return context


class CustomUserCreateView(CreateView):
    model = CustomUser
    fields = ['username', 'public_key', 'e']
    success_url = reverse_lazy('user-list')

    def form_valid(self, form):
        self.object = form.save(commit=False)
        # self.object.user = self.request.user
        self.object.save()
        return HttpResponseRedirect(self.get_success_url())

    def get_initial(self, *args, **kwargs):
        initial = super(CustomUserCreateView, self).get_initial(**kwargs)
        return initial

    def get_form_kwargs(self, *args, **kwargs):
        kwargs = super(CustomUserCreateView, self).get_form_kwargs(*args, **kwargs)
        # kwargs['user'] = self.request.user
        return kwargs
