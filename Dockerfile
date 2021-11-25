FROM centos:7

RUN yum -y update &&\
	yum -y install gcc gcc-c++ vim &&\
	yum -y update vim* -y &&\
	yum -y install make &&\
	yum -y --setopt=tsflags='' install man man-pages

ENV LANG=en_US.UTF-8

