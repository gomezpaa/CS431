PROGRAM GHP5
  IMPLICIT NONE
  ! ===========================================================================
  ! = Written by Paolo Gomez                                                  =
  ! = Written in Fortran 95                                                   =
  ! = 02 December, 2022                                                       =
  ! = Program reads the integers from a file and sorts the integers           =
  ! = using quicksort and selection sort and displays the results to the user =
  ! ===========================================================================
  INTEGER, DIMENSION(100) :: SelectArray
  REAL, DIMENSION(100) :: QuickArray
  INTEGER :: i, temp
  open(1, file = 'random_numbers.txt', status='old')
  DO i = 1,100
    read(1,*) SelectArray(i)
  END DO
  
  QuickArray = SelectArray
 
  WRITE(*,"(A,100I5)") "Unsorted array:", SelectArray
  CALL Selection_sort(SelectArray)
  WRITE(*,"(A,100I5)") "Sorted array using Selection Sort  :", SelectArray
  CALL QuickSort(QuickArray, 100)
  WRITE(*,"(A,100F5.0)") "Sorted array using Quick Sort  :", QuickArray
  
 
CONTAINS
  
  RECURSIVE SUBROUTINE QuickSort(array,length)
  
  ! =======================================
  ! = Written by Paolo Gomez              =
  ! = Written in Fortran 95               =
  ! = 02 December 2022                    =
  ! = Function that handles the quicksort =
  ! =======================================
    INTEGER, INTENT(in) :: length
    REAL, DIMENSION(length), INTENT(in out) :: array
    REAL :: random, pivot, temp
    INTEGER :: left, right, marker
 
    IF (length > 1) THEN
       CALL random_NUMBER(random)
       pivot = array(INT(random*REAL(length-1))+1)
       left = 1
       right = length
       DO
          IF (left >= right) EXIT
          DO
             IF (array(right) <= pivot) EXIT
             right = right - 1
          END DO
          DO
             IF (array(left) >= pivot) EXIT
             left = left + 1
          END DO
          IF (left < right) THEN
             temp = array(left)
             array(left) = array(right)
             array(right) = temp
          END IF
       END DO
       IF (left == right) THEN
          marker = left + 1
       ELSE
          marker = left
       END IF
       CALL QuickSort(array(:marker-1),marker-1)
       CALL QuickSort(array(marker:),length-marker+1)
    END IF
  END SUBROUTINE QuickSort
  
  SUBROUTINE Selection_sort(array)
  ! ========================================
  ! = Written by Paolo Gomez               =
  ! = Written in Fortran 95                =
  ! = 02 December 2022                     =
  ! = Function that handles Selection sort =
  ! ========================================
    INTEGER, INTENT(IN OUT) :: array(:)
    INTEGER :: i, minNum, temp
    DO i = 1, SIZE(array)-1
       minNum = MINLOC(array(i:), 1) + i - 1
       IF (array(i) > array(minNum)) THEN
          temp = array(i)
          array(i) = array(minNum)
          array(minNum) = temp
       END IF
    END DO
  END SUBROUTINE Selection_sort
  
END PROGRAM GHP5
