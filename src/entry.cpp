#include "core.h"
#include "entry.h"
#include <glad/glad.h>

int main(int argc, char** argv)
{
	tempNameInit();
	createWClass();
	window* handle = createWindow(L"something",1080,720);
	setContext(handle);
	int status = gladLoadGLLoader((GLADloadproc)getProcName);

	uint32_t m_VertexArray{}, m_VertexBuffer{}, m_IndexBuffer{};
	//init
	glCreateVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);

	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	float vertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	unsigned indices[3] = { 0,1,2 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	//set callbacks
	bool running = true;
	while (handle->flags != shouldClose) {
		//drawing
		glClearColor(0, 0.6f, 0.6f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(m_VertexArray);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		pollEvents();
		swapBuffers(handle);
	}
	destroyWindow(handle);
}

