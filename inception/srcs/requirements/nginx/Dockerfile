FROM alpine:3.16

RUN apk update && apk upgrade && apk add --no-cache nginx openssl
RUN openssl req -newkey rsa:4096 \
				-days 365 \
				-nodes \
				-x509 \
				-subj "/C=KR/ST=KR/L=Seoul/O=42Seoul/OU=Gun/CN=$DOMAIN_NAME/E=$EMAIL" \
				-keyout /etc/ssl/private/nginx.key \
				-out /etc/ssl/certs/nginx.crt && \
	ln -sf /dev/stdout /var/log/nginx/access.log && \
	ln -sf /dev/stderr /var/log/nginx/error.log

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
