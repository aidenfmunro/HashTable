import aspose.words as aw
import sys

fileNames = [sys.argv[1], sys.argv[2]]

doc = aw.Document()
builder = aw.DocumentBuilder(doc)

shapes = [builder.insert_image(fileName) for fileName in fileNames]

# Вычислить максимальную ширину и высоту и обновить настройки страницы, 
# чтобы обрезать документ по размеру изображений.

pageSetup               = builder.page_setup
pageSetup.page_width    = max(shape.width for shape in shapes)
pageSetup.page_height   = sum(shape.height for shape in shapes)
pageSetup.top_margin    = 0
pageSetup.left_margin   = 0
pageSetup.bottom_margin = 0
pageSetup.right_margin  = 0

doc.save(sys.argv[3])