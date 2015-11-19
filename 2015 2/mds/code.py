import web

urls = (
	'/', 'index'
)

class index():
	def GET(self):
		f = open('index.html')
		page = f.read()
		f.close
		return page

app = web.application(urls, globals())

if __name__ == "__main__":
    app.run()