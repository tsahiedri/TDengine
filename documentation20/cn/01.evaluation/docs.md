# TDengine 介绍

## <a class="anchor" id="intro"></a>TDengine 简介

TDengine 是涛思数据面对高速增长的物联网大数据市场和技术挑战推出的创新性的大数据处理产品，它不依赖任何第三方软件，也不是优化或包装了一个开源的数据库或流式计算产品，而是在吸取众多传统关系型数据库、NoSQL 数据库、流式计算引擎、消息队列等软件的优点之后自主开发的产品，在时序空间大数据处理上，有着自己独到的优势。

TDengine 的模块之一是时序数据库。但除此之外，为减少研发的复杂度、系统维护的难度，TDengine 还提供缓存、消息队列、订阅、流式计算等功能，为物联网、工业互联网大数据的处理提供全栈的技术方案，是一个高效易用的物联网大数据平台。与 Hadoop 等典型的大数据平台相比，它具有如下鲜明的特点：

* __10 倍以上的性能提升__：定义了创新的数据存储结构，单核每秒能处理至少 2 万次请求，插入数百万个数据点，读出一千万以上数据点，比现有通用数据库快十倍以上。
* __硬件或云服务成本降至 1/5__：由于超强性能，计算资源不到通用大数据方案的 1/5；通过列式存储和先进的压缩算法，存储空间不到通用数据库的 1/10。
* __全栈时序数据处理引擎__：将数据库、消息队列、缓存、流式计算等功能融为一体，应用无需再集成 Kafka/Redis/HBase/Spark/HDFS 等软件，大幅降低应用开发和维护的复杂度成本。 
* __强大的分析功能__：无论是十年前还是一秒钟前的数据，指定时间范围即可查询。数据可在时间轴上或多个设备上进行聚合。即席查询可通过 Shell, Python, R, MATLAB 随时进行。
* __与第三方工具无缝连接__：不用一行代码，即可与 Telegraf, Grafana, EMQ, HiveMQ, Prometheus, MATLAB, R 等集成。后续将支持 OPC, Hadoop, Spark 等，BI 工具也将无缝连接。
* __零运维成本、零学习成本__：安装集群简单快捷，无需分库分表，实时备份。类标准 SQL，支持 RESTful，支持 Python/Java/C/C++/C#/Go/Node.js, 与 MySQL 相似，零学习成本。

采用 TDengine，可将典型的物联网、车联网、工业互联网大数据平台的总拥有成本大幅降低。但需要指出的是，因充分利用了物联网时序数据的特点，它无法用来处理网络爬虫、微博、微信、电商、ERP、CRM 等通用型数据。

![TDengine技术生态图](page://images/eco_system.png)
<center>图 1. TDengine技术生态图</center>


## <a class="anchor" id="scenes"></a>TDengine 总体适用场景

作为一个 IoT 大数据平台，TDengine 的典型适用场景是在 IoT 范畴，而且用户有一定的数据量。本文后续的介绍主要针对这个范畴里面的系统。范畴之外的系统，比如 CRM，ERP 等，不在本文讨论范围内。


### 数据源特点和需求

从数据源角度，设计人员可以从下面几个角度分析 TDengine 在目标应用系统里面的适用性。

|数据源特点和需求|不适用|可能适用|非常适用|简单说明|
|---|---|---|---|---|
|总体数据量巨大|  |  | √ | TDengine 在容量方面提供出色的水平扩展功能，并且具备匹配高压缩的存储结构，达到业界最优的存储效率。|
|数据输入速度偶尔或者持续巨大|   |   | √ | TDengine 的性能大大超过同类产品，可以在同样的硬件环境下持续处理大量的输入数据，并且提供很容易在用户环境里面运行的性能评估工具。|
|数据源数目巨大|   |   | √ | TDengine 设计中包含专门针对大量数据源的优化，包括数据的写入和查询，尤其适合高效处理海量（千万或者更多量级）的数据源。|

### 系统架构要求

|系统架构要求|不适用|可能适用|非常适用|简单说明|
|---|---|---|---|---|
|要求简单可靠的系统架构|  |  | √ | TDengine 的系统架构非常简单可靠，自带消息队列，缓存，流式计算，监控等功能，无需集成额外的第三方产品。|
|要求容错和高可靠|  |  | √ | TDengine 的集群功能，自动提供容错灾备等高可靠功能。|
|标准化规范|  |  | √ | TDengine 使用标准的 SQL 语言提供主要功能，遵守标准化规范。|

### 系统功能需求

|系统功能需求|不适用|可能适用|非常适用|简单说明|
|---|---|---|---|---|
|要求完整的内置数据处理算法|  | √ |  | TDengine 的实现了通用的数据处理算法，但是还没有做到妥善处理各行各业的所有要求，因此特殊类型的处理还需要应用层面处理。|
|需要大量的交叉查询处理|  | √ |  |这种类型的处理更多应该用关系型数据系统处理，或者应该考虑 TDengine 和关系型数据系统配合实现系统功能。|

### 系统性能需求

|系统性能需求|不适用|可能适用|非常适用|简单说明|
|---|---|---|---|---|
|要求较大的总体处理能力|  |  | √ | TDengine 的集群功能可以轻松地让多服务器配合达成处理能力的提升。|
|要求高速处理数据  | | | √ | TDengine 的专门为 IoT 优化的存储和数据处理的设计，一般可以让系统得到超出同类产品多倍数的处理速度提升。|
|要求快速处理小粒度数据|  |  | √ |这方面 TDengine 性能可以完全对标关系型和 NoSQL 型数据处理系统。|

### 系统维护需求

|系统维护需求|不适用|可能适用|非常适用|简单说明|
|---|---|---|---|---|
|要求系统可靠运行|  |  | √ | TDengine 的系统架构非常稳定可靠，日常维护也简单便捷，对维护人员的要求简洁明了，最大程度上杜绝人为错误和事故。|
|要求运维学习成本可控|  |  | √ |同上。|
|要求市场有大量人才储备| √ |  |  | TDengine 作为新一代产品，目前人才市场里面有经验的人员还有限。但是学习成本低，我们作为厂家也提供运维的培训和辅助服务。|

