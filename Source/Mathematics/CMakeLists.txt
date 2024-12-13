set(SOURCE_MATHEMATICS
   ${PROJECT_SOURCE_DIR}/Source/Mathematics/Math.c
   ${PROJECT_SOURCE_DIR}/Source/Mathematics/Vector2F.c
   ${PROJECT_SOURCE_DIR}/Source/Mathematics/Vector3F.c
)

set(INCLUDE_MATHEMATICS
   ${PROJECT_SOURCE_DIR}/Include/Mathematics/Math.h
   ${PROJECT_SOURCE_DIR}/Include/Mathematics/Vector2F.h
   ${PROJECT_SOURCE_DIR}/Include/Mathematics/Vector3F.h
)

set(SOURCE_MATHEMATICS "${SOURCE_MATHEMATICS}" PARENT_SCOPE)
set(INCLUDE_MATHEMATICS "${INCLUDE_MATHEMATICS}" PARENT_SCOPE)