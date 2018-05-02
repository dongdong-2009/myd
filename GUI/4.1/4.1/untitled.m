function varargout = untitled(varargin)
% UNTITLED MATLAB code for untitled.fig
%      UNTITLED, by itself, creates a new UNTITLED or raises the existing
%      singleton*.
%
%      H = UNTITLED returns the handle to a new UNTITLED or the handle to
%      the existing singleton*.
%
%      UNTITLED('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in UNTITLED.M with the given input arguments.
%
%      UNTITLED('Property','Value',...) creates a new UNTITLED or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before untitled_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to untitled_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help untitled

% Last Modified by GUIDE v2.5 01-May-2018 23:45:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @untitled_OpeningFcn, ...
                   'gui_OutputFcn',  @untitled_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before untitled is made visible.
function untitled_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to untitled (see VARARGIN)

% Choose default command line output for untitled
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes untitled wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = untitled_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function edit7_Callback(hObject, eventdata, handles)
% hObject    handle to edit7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit7 as text
%        str2double(get(hObject,'String')) returns contents of edit7 as a double


% --- Executes during object creation, after setting all properties.
function edit7_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit8_Callback(hObject, eventdata, handles)
% hObject    handle to edit8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit8 as text
%        str2double(get(hObject,'String')) returns contents of edit8 as a double


% --- Executes during object creation, after setting all properties.
function edit8_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit9_Callback(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit9 as text
%        str2double(get(hObject,'String')) returns contents of edit9 as a double


% --- Executes during object creation, after setting all properties.
function edit9_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit10_Callback(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit10 as text
%        str2double(get(hObject,'String')) returns contents of edit10 as a double


% --- Executes during object creation, after setting all properties.
function edit10_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2


% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit12_Callback(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit12 as text
%        str2double(get(hObject,'String')) returns contents of edit12 as a double


% --- Executes during object creation, after setting all properties.
function edit12_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton11.
function pushbutton11_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global A;
[FileName,PathName,FilterIndex]=uigetfile('FilterSpec','dialogTile',500,500);
handles.filename=FileName;
strdata=strcat(PathName,FileName);
set(handles.edit1,'string',strdata);
A=xlsread(FileName);
Xa=min(A);   %数据最小值
set(handles.edit13,'string',num2str(Xa));
Xb=max(A);  %数据最大值
set(handles.edit14,'string',num2str(Xb));
guidata(hObject,handles);

B = A;
C = zeros(0,0);
for j = 1 : 3

    S = std(B);
    P = mean(B);
    n = length(B);
    B = zeros(0,0);
    
    Gn = log(n-3)/2.3 + 1.36 - n/550
    for i = 1 : n
        if((A(i) >= (P-(Gn * S)))&&(A(i) <= (P+(Gn * S))))
            B = [B;A(i)];
        else
            C = [C;A(i)];
        end
    end
   
end
   set(handles.editGn,'string',num2str(B));
   set(handles.editinvaliddata,'string',num2str(C));
    n = length(B)
    Gn = log(n-3)/2.3 + 1.36 - n/550;
    set(handles.edit17,'string',num2str(Gn))
   
   
function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global A;
% A=[2.054,2.056,1.947,2.076,2.011,2.042,2.007,2.026,2.047,2.075,2.083,2.046,2.061,2.090,1.995,2.047,2.120,2.011,2.031,2.057,2.085,2.102,2.079,2.055,2.005,2.000,2.023,1.941,2.027,2.061,1.995,2.033,1.995,2.044,2.075,2.067,2.069,2.064,1.992,1.997,2.050,2.034,2.007,2.006,2.120,2.092,1.994,2.021,2.020,2.015,2.036,1.977,2.024,2.029,1.979,2.042,2.015,2.027,1.994,2.049,1.998,2.092,2.032,2.067,2.012,2.100,1.973,2.009,2.087,2.041,2.071,2.062,2.025,1.973,1.971,2.058,2.000,2.090,1.963,2.093,2.052,2.063,2.076,2.026,2.019,1.990,2.023,2.009,2.011,2.105,2.014,2.032,2.009,1.974,2.046,2.038,2.105,1.988,2.012,2.083,1.980,2.022,2.040,2.020,1.985];
S=std(A);   %实验平均值
set(handles.edit3,'string',num2str(S));

% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% A=[2.054,2.056,1.947,2.076,2.011,2.042,2.007,2.026,2.047,2.075,2.083,2.046,2.061,2.090,1.995,2.047,2.120,2.011,2.031,2.057,2.085,2.102,2.079,2.055,2.005,2.000,2.023,1.941,2.027,2.061,1.995,2.033,1.995,2.044,2.075,2.067,2.069,2.064,1.992,1.997,2.050,2.034,2.007,2.006,2.120,2.092,1.994,2.021,2.020,2.015,2.036,1.977,2.024,2.029,1.979,2.042,2.015,2.027,1.994,2.049,1.998,2.092,2.032,2.067,2.012,2.100,1.973,2.009,2.087,2.041,2.071,2.062,2.025,1.973,1.971,2.058,2.000,2.090,1.963,2.093,2.052,2.063,2.076,2.026,2.019,1.990,2.023,2.009,2.011,2.105,2.014,2.032,2.009,1.974,2.046,2.038,2.105,1.988,2.012,2.083,1.980,2.022,2.040,2.020,1.985];
global A;
P=mean(A);   %实验平均值
set(handles.edit2,'string',num2str(P));
function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double


% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double


% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit4_Callback(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit4 as text
%        str2double(get(hObject,'String')) returns contents of edit4 as a double


% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global A;
Gn = str2double(get(handles.edit7,'String'));
m=str2double(get(handles.edit4,'String'));
% A=[2.054,2.056,1.947,2.076,2.011,2.042,2.007,2.026,2.047,2.075,2.083,2.046,2.061,2.090,1.995,2.047,2.120,2.011,2.031,2.057,2.085,2.102,2.079,2.055,2.005,2.000,2.023,1.941,2.027,2.061,1.995,2.033,1.995,2.044,2.075,2.067,2.069,2.064,1.992,1.997,2.050,2.034,2.007,2.006,2.120,2.092,1.994,2.021,2.020,2.015,2.036,1.977,2.024,2.029,1.979,2.042,2.015,2.027,1.994,2.049,1.998,2.092,2.032,2.067,2.012,2.100,1.973,2.009,2.087,2.041,2.071,2.062,2.025,1.973,1.971,2.058,2.000,2.090,1.963,2.093,2.052,2.063,2.076,2.026,2.019,1.990,2.023,2.009,2.011,2.105,2.014,2.032,2.009,1.974,2.046,2.038,2.105,1.988,2.012,2.083,1.980,2.022,2.040,2.020,1.985];
%  Gn=3.62;    %格拉布斯判据系数
S=std(A);  %实验标准差
P=mean(A);   %实验平均值
B=A(A>=(P-(Gn*S))&A<=(P+(Gn*S)));    %剔除坏数据
N=length(B);   %保留样本的个数
Nn=floor(N/10);  %把样本分组
for i=1:Nn
j=i*10;
P1(i)=mean(B(1:j));
S1(i)=std(B(1:j));
end    %每组数据的平均值p和标准差s
S1=S1(i);
set(handles.edit6,'string',num2str(S1));
% m=7;
Xa=min(A);   %数据最小值
Xb=max(A);  %数据最大值
E=(Xb-Xa)/m;  %区间宽度

% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global A;
Gn = str2double(get(handles.edit7,'String'));
m=str2double(get(handles.edit4,'String'));
% A=[2.054,2.056,1.947,2.076,2.011,2.042,2.007,2.026,2.047,2.075,2.083,2.046,2.061,2.090,1.995,2.047,2.120,2.011,2.031,2.057,2.085,2.102,2.079,2.055,2.005,2.000,2.023,1.941,2.027,2.061,1.995,2.033,1.995,2.044,2.075,2.067,2.069,2.064,1.992,1.997,2.050,2.034,2.007,2.006,2.120,2.092,1.994,2.021,2.020,2.015,2.036,1.977,2.024,2.029,1.979,2.042,2.015,2.027,1.994,2.049,1.998,2.092,2.032,2.067,2.012,2.100,1.973,2.009,2.087,2.041,2.071,2.062,2.025,1.973,1.971,2.058,2.000,2.090,1.963,2.093,2.052,2.063,2.076,2.026,2.019,1.990,2.023,2.009,2.011,2.105,2.014,2.032,2.009,1.974,2.046,2.038,2.105,1.988,2.012,2.083,1.980,2.022,2.040,2.020,1.985];
%  Gn=3.62;    %格拉布斯判据系数
S=std(A);  %实验标准差
P=mean(A);   %实验平均值
B=A(A>=(P-(Gn*S))&A<=(P+(Gn*S)));    %剔除坏数据
N=length(B);   %保留样本的个数
Nn=floor(N/10);  %把样本分组
for i=1:Nn
j=i*10;
P1(i)=mean(B(1:j));
S1(i)=std(B(1:j));
end    %每组数据的平均值p和标准差s
P1=P1(i);
set(handles.edit5,'string',num2str(P1));
% m=7;
Xa=min(A);   %数据最小值
Xb=max(A);  %数据最大值
E=(Xb-Xa)/m;  %区间宽度


function edit5_Callback(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit5 as text
%        str2double(get(hObject,'String')) returns contents of edit5 as a double


% --- Executes during object creation, after setting all properties.
function edit5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit6_Callback(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit6 as text
%        str2double(get(hObject,'String')) returns contents of edit6 as a double


% --- Executes during object creation, after setting all properties.
function edit6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton13.
function pushbutton13_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% A=[2.054,2.056,1.947,2.076,2.011,2.042,2.007,2.026,2.047,2.075,2.083,2.046,2.061,2.090,1.995,2.047,2.120,2.011,2.031,2.057,2.085,2.102,2.079,2.055,2.005,2.000,2.023,1.941,2.027,2.061,1.995,2.033,1.995,2.044,2.075,2.067,2.069,2.064,1.992,1.997,2.050,2.034,2.007,2.006,2.120,2.092,1.994,2.021,2.020,2.015,2.036,1.977,2.024,2.029,1.979,2.042,2.015,2.027,1.994,2.049,1.998,2.092,2.032,2.067,2.012,2.100,1.973,2.009,2.087,2.041,2.071,2.062,2.025,1.973,1.971,2.058,2.000,2.090,1.963,2.093,2.052,2.063,2.076,2.026,2.019,1.990,2.023,2.009,2.011,2.105,2.014,2.032,2.009,1.974,2.046,2.038,2.105,1.988,2.012,2.083,1.980,2.022,2.040,2.020,1.985];
global A;
S=std(A);  %实验标准差
P=mean(A);   %实验平均值
%  Gn=3.62;    %格拉布斯判据系数
Gn = str2double(get(handles.edit7,'String'));
m=str2double(get(handles.edit4,'String'));
B=A(A>=(P-(Gn*S))&A<=(P+(Gn*S)));    %剔除坏数据
N=length(B);   %保留样本的个数
Nn=floor(N/10);  %把样本分组
for i=1:Nn
j=i*10;
P1(i)=mean(B(1:j));
S1(i)=std(B(1:j));
end    %每组数据的平均值p和标准差s
% m=7;
Xa=min(A);   %数据最小值
Xb=max(A);  %数据最大值
E=(Xb-Xa)/m;  %区间宽度

for M=1:m
ni(M)=length(find(A>=(Xa+(M-1)*E)&A<=(Xa+(M*E))));
Xfi(M)=Xa+(E*M);
end  %分区频率
f=ni/N;  %频率
v=ni/(N*E);  %频率密度
ns=length(find(A>=(P-S)&A<=(P+S)));
L=ns/N;   %ns/n值
Xf=[Xfi-(E*0.5)];  %柱状图x值
C=sort(A);  %概率密度曲线x值
Px=(1/(S*sqrt(2*pi)))*exp((-(C-P).^2)/(2*(S.^2)));   %概率密度函数
axes(handles.axes1)
plot(C,Px,'--');  %概率密度曲线
n=10:10:N;  %折线图x轴
axes(handles.axes3)
plotyy(n,S1,n,P1) %做出标准差折线图
xlabel('n')  %横坐标名
ylabel('S/s,P/s')   %纵坐标名
axes(handles.axes2)
 bar(v);
set(gca , 'XTickLabel' , [Xf]);



function edit13_Callback(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit13 as text
%        str2double(get(hObject,'String')) returns contents of edit13 as a double


% --- Executes during object creation, after setting all properties.
function edit13_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit14_Callback(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit14 as text
%        str2double(get(hObject,'String')) returns contents of edit14 as a double


% --- Executes during object creation, after setting all properties.
function edit14_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editinvaliddata_Callback(hObject, eventdata, handles)
% hObject    handle to editinvaliddata (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editinvaliddata as text
%        str2double(get(hObject,'String')) returns contents of editinvaliddata as a double


% --- Executes during object creation, after setting all properties.
function editinvaliddata_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editinvaliddata (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editGn_Callback(hObject, eventdata, handles)
% hObject    handle to editGn (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editGn as text
%        str2double(get(hObject,'String')) returns contents of editGn as a double


% --- Executes during object creation, after setting all properties.
function editGn_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editGn (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit17_Callback(hObject, eventdata, handles)
% hObject    handle to edit17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit17 as text
%        str2double(get(hObject,'String')) returns contents of edit17 as a double


% --- Executes during object creation, after setting all properties.
function edit17_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
